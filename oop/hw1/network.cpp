#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Route
{
    string IP;
    int indx_in_vect;
    int count_pakages;
};


class Package
{
    char * content;
    int content_len;
    string IP_sender;
    string IP_receiver;
    int package_num;

public:
    static int counter;

    Package(const char * content, string IP_sender, string IP_receiver)
    {   
        if(IP_receiver == "0.0.0.0" || IP_receiver == "127.0.0.0" || 
            IP_sender == "0.0.0.0" || IP_sender == "127.0.0.0") 
            throw "Wrong IP";

        if(*content == '\0') throw "Empty content";

        this->content = new char[sizeof(content)];
        strcpy(this->content, content);
        this->IP_receiver = IP_receiver;
        this->IP_sender = IP_sender;

        package_num = ++counter;
    }

    int get_num_of_pack()
    {
        return package_num;
    }

    char * get_content()
    {
        return content;
    }

    string get_IP_receiver()const
    {
        return IP_receiver;
    }

    int validate()
    {
        if(strlen(this->content) == this->content_len) return 1;
        return 0;
    }

    ~Package()
    {
        delete[] content;
    }

};


int Package::counter = 0;


class Router
{
    string name;
    string IP;
    vector< Router *> routers;
    list<Route> routing_table;
    const static int max_el_list;
    static const int max_hops;
    int sum_of_packages;

public:

    Router(string name, string IP)
    {
        this->name = name;
        this->IP = IP;
        sum_of_packages = 0;

        // max_hops += 1;
        // max_el_list += 1;
    }

    string get_name()
    {
        return name;
    }

    vector< Router *> get_vect()
    {
        return routers;
    }

    void add_router(Router& router) // CONST?!
    {
        routers.push_back(&router);
    }

    int query_route(const string address, const int hop_count)
    {
        if(IP == address) return 1;

        for (auto i = routing_table.begin(); i != routing_table.end(); i++)
        {
            if((i)->IP == address) return 1;    
        }
        int indx = 0;
        if(hop_count > 1)
        {
            for (auto i = routers.begin(); i != routers.end(); i++, indx++)
            {
                if((*i)->query_route(address, hop_count - 1) == 1)
                {
                    Route new_route;
                    new_route.IP = address;
                    if(address == "0.0.0.0" || address == "127.0.0.0") 
                    throw "Wrong IP";
                    new_route.indx_in_vect = indx;
                    if(routing_table.size() == max_el_list)
                    {
                        routing_table.pop_back();
                    }
                    routing_table.push_back(new_route);

                    return 1;
                }
            }
        }
        return 0;
    }

    void sort(list<Route> routing_table)
    {
        for (auto i = routing_table.begin(); i != routing_table.end(); i++)
        {
            for (auto j = i++; j != routing_table.end(); j++)

            if((i++)->count_pakages > i->count_pakages)
            {
                Route tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }

    void send_package(const Package& package)
    {
        Package pack = package;
        if(strcmp(pack.get_content(),"\0") == 1) throw "Empty content";
        
        if(IP == package.get_IP_receiver())
        {
            cout << "found and send" << endl;
            return;
        }

        for (auto i = routing_table.begin(); i != routing_table.end(); i++)
        {
            if(i->IP == package.get_IP_receiver())
            {
                i->count_pakages += 1;
                sum_of_packages++;
                if(sum_of_packages % 10 == 0) sort(routing_table);
                
                routers[i->indx_in_vect]->send_package(package);   
            }  
        }
        if(query_route(package.get_IP_receiver(), max_hops) == 0)
        {
            cout << "not found" << endl;
        }
        else send_package(package);
        return;
    }
};


vector<Router *> read_and_create_vect()
{
    ifstream istream;
    istream.open("routers.txt");
    string name;
    string IP;
    string word;
    vector<Router* > res;
    Router* new_router;

    while(istream.eof() == 0)
    {
        getline(istream, name, ' ');
        getline(istream, IP);
        new_router = new Router(name, IP);
        res.push_back(new_router);
    }
    
    delete [] new_router;

    return res;
}

void add(vector<Router *> res)
{
    ifstream istream;
    istream.open("network.txt");
    string rut1;
    string rut2;
    Router* router1;
    Router* router2;

    getline(istream, rut1, ' ');
    getline(istream, rut2);
    for (int i = 0; i < res.size(); i++)
    {
        if(res[i]->get_name() == rut1)
        {
            router1 = res[i];
        }
        else if(res[i]->get_name() == rut2)
        {
            router2 = res[i];
        }
    }
    router1->add_router(*router2);
    router2->add_router(*router1);
     
}

vector<Package> read_pack()
{
    ifstream istream;
    istream.open("packages.txt");
    string source_address;
    string target_address;
    string hehe;
    string content;
    vector<Package> packages;

    while(istream.eof() == 0)
    {
        getline(istream, source_address, ' ');
        getline(istream, target_address, ' ');
        getline(istream, hehe, '"');
        getline(istream, content, '"');

        char content_fin[content.length()+1];
        strcpy(content_fin, content.c_str());
        content_fin[content.length()] = 0;

        Package pack = Package(content_fin, source_address, target_address);
        packages.push_back(pack);

    }

    return packages;

}

int main()
{
    try
    {
        Package pack1 = Package("jklodaco", "0.0.0.0", "567.23.45.76");
        cout << pack1.get_num_of_pack() << '\n';
        Package pack2 = Package("jklco", "212.38.26", "567.23.76");
        cout << pack2.get_num_of_pack() << '\n';

    }
    catch(const char *)
    {
        cout << "Error" << '\n';
    }


    return 0;
}

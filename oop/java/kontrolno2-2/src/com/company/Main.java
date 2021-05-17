package com.company;
import java.util.*;
//Работа на програмата
//        Потребителят въвежда брой посеви(цяло число) и ги изброява(стрингове с техните имена и видове).
//        След това изброява наличните инструменти на земеделеца(като стрингове).
//        С горната информация се инициализират списъка с посеви и обектът за земеделец.
//        Накрая това въвежда колко дни(цяло число) да продължи работата на земеделеца.
//        След въвеждането програмата да се реализира като цикъл от 0 до броя въведени дни. За всеки ден земеделецът
//        преминава един след друг през посевите и върши върху тях каквата работа може с инструментите, които има.
//        Логиката за обхождане на дните се намира извън класа за земеделец. Логиката за обхождане и обработване на посеви
//        се намира в класа за земеделец!
//        Накрая да се изпише информация за посевите:
//        кои са били обрани успешно
//        кои са останали необрани
//        кои са умрели

public class Main {

    public static void main(String[] args) {
        Vegetables vegi1 = new Vegetables("Domat4e");
        Fruit fruiti1 = new Fruit("Praskovka");
        Cactus catus1 = new Cactus("vid1");
        String tool1 = "lejka";
        String tool2 = "motika";
        String tool3 = "stulba";

        List<Sowing> posevi = new ArrayList<>();
        posevi.add(vegi1);
        posevi.add(fruiti1);
        posevi.add(catus1);

        Worker worker = new Worker("Geri");
        worker.addTools(tool1);
        worker.addTools(tool2);
        worker.addTools(tool2);

        int daysWork = 5;

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < posevi.size(); j++) {
                worker.allWork(posevi.get(j));
                posevi.get(j).addDay();
            }

        }


//        for (int j = 0; j < posevi.size(); j++) {
//            if(posevi.get(j).getIsDead() == true)
//            System.out.print("dead: ", posevi.get(j).toString());
//
//            if(posevi.get(j).isSelected() == true)
//                System.out.print("Selsected: ",  posevi.get(j).toString());
//
//            if(posevi.get(j).isSelected() == false)
//                System.out.print("not setected: ", posevi.get(j).toString());
//        }

    }
}

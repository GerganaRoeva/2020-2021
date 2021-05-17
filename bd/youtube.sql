drop database if exists Youtube;
create database Youtube;
use Youtube;

create table Potrebitel(
    id int not null primary key auto_increment,
    name varchar(50) unique
);

create table Kanal(
    id int not null primary key auto_increment,
    name varchar(50) unique
);

create table PoterbitelKanal(
    id int not null primary key auto_increment,
    potrbilet_id int not null ,
    foreign key (potrbilet_id) references Potrebitel(id),
    kanal_id int not null,
    foreign key (kanal_id) references Kanal(id),
    constraint UniquePoterbitelKanal Unique(kanal_id, potrbilet_id)
);

create table Video(
    id int not null primary key auto_increment,
    tatle varchar(50) unique,
    kanal_id int not null,
    foreign key (kanal_id) references Kanal(id)
);

create table Komentar(
    id int not null primary key auto_increment,
    value varchar(50) unique,
    video_id int not null,
    foreign key (video_id) references Video(id)
);

insert into Potrebitel(name) values("Geri");
insert into Potrebitel(name) values("Gosho");
insert into Potrebitel(name) values("Grisho");

insert into Kanal(name) values("Qki kotki");
insert into Kanal(name) values("Qki ku4eta");
insert into Kanal(name) values("Qki ptici");

insert into PoterbitelKanal(potrbilet_id, kanal_id) values(1,1);
insert into PoterbitelKanal(potrbilet_id, kanal_id) values(2,2);
insert into PoterbitelKanal(potrbilet_id, kanal_id) values(3,3);

insert into Video(tatle, kanal_id) values("top 10 qki kotki", 1);
insert into Video(tatle, kanal_id) values("top 10 qki ku4eta", 2);
insert into Video(tatle, kanal_id) values("top 10 qki ptici", 3);

select Video.tatle, Komentar.value, Potrebitel.name, Kanal.name from Komentar
left join Video
on Video.id = Komentar.video_id
left join Potrebitel
on Potrebitel.id = Komentar.potrbilet_id
left join Kanal
on Video.id = Komentar.video_id

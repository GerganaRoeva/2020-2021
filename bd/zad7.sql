drop database if exists db;
create database db;
use db;

create table student(
    id int not null primary key auto_increment,
    name varchar(100) unique
);

-- така един учебник може да се ползва от един ученик
-- един ученик множе да има много различни учебници
create table book(
    id int not null primary key auto_increment,
    subject varchar(100) unique,
    studeny_id int not null unique,
    foreign key (studeny_id) references student(id)
);

create table computer(
    id int not null primary key auto_increment
);

-- many to many със повтаряне
create table StudentComp(
    id int not null primary key auto_increment,
    student_id int not null,
    foreign key (student_id) references student(id),
    computer_id int not null,
    foreign key (computer_id) references computer(id)
    -- constraint UniqueStudentComp Unique(student_id, computer_id) --ако е без повтаряне
);

-- 1 segregaciq i integraciq
-- 2 sufravetkite
-- 3 malcinstawa na balkanie
-- 4Malcinstwa
-- 5kolonii
-- 6 genocid
-- 7 

select Profile.name, Post.description, Post.type From Profile
right join Post
on Profile.id = Post.profile_id;
-- where Post.type is not null;
select Profile.name as "Owner",
Post.description,
Komentar.content,
Profile.name as "komentiral"
from Post
right join Komentar
on Komentar.post_id = Post.id
left join Profile as komentiral
on Profile.id = komentiral.profile_id
left join Profile as owner
on Profile.id = owner.profile_id;

select owner.name, Post.description, Postliker.name, Llike.id
from Llike
left join Post
on Post.id = Llike.profile_id
left join Profile as owner
on owner.id = Post.profile_id
left join Profile as Postliker
on Postliker.id = Llike.profile_id;
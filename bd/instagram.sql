
drop database if exists instagram;
create database instagram;
use instagram;

create table Profile (
  id int not null primary key auto_increment,
  name varchar(100) unique
);

create table Post(
  id int not null primary key auto_increment,
  description varchar(100),
  type ENUM('post', 'video'),
  profile_id int not null,
  foreign key (profile_id) references Profile(id)
);

create table Komentar(
  id int not null primary key auto_increment,
  content varchar(500) not null,
  post_id int not null,
  foreign key (post_id) references Post(id),
  profile_id int not null,
  foreign key (profile_id) references Profile(id)
);

create table Llike(
  id int not null primary key auto_increment,
  post_id int not null,
  foreign key (post_id) references Post(id),
  profile_id int not null,
  foreign key (profile_id) references Profile(id)
);

insert into Profile(name) values ("misho");
insert into Profile(name) values ("nasko");
insert into Profile(name) values ("mimi");

insert into Post(description, type, profile_id) values ("not clickbait i give u money", "Video",1);
insert into Post(description, type, profile_id) values ("not clickbait i give u money 2" ,"Video", 1);
insert into Post(description, type, profile_id) values ("fun du ten","Video", 2);

insert into Komentar(content, post_id, profile_id) values ("purwi sum tuka", 1, 1);

-- select * from Post
-- left join Komentar
-- on Post.id = Komentar.post_id
-- where Komentar.content is NULL;

-- select * from Post
-- left join Komentar
-- on Post.id = Komentar.post_id
-- left join Llike
-- on Post.id = Llike.post_id
-- where Llike.post_id is NULL or Komentar.content is NULL;

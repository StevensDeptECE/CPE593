create table a (
  id int primary key,
  firstName char(20),
  lastName char(20)
  )


select * from A where id = 1212			O(log n)
select * from a where firstName like 'D%'	O(n)

create index of a.firstName

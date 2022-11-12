# Write your MySQL query statement below

select person.firstName, person.lastName, address.state, address.city
from person
left join address
on person.personId = address.personId
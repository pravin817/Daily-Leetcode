# Write your MySQL query statement below

SELECT person.firstName as firstName,
person.lastName as lastName,
address.city as city,
address.state as state
FROM Person as person
LEFT JOIN Address as address
ON person.personId = address.personId;
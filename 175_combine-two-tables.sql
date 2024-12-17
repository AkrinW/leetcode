select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId;

-- SELECT column_name(s)
-- FROM table_name(s)
-- [JOIN ... ON ...]
-- [WHERE condition]
-- [GROUP BY column_name(s)]
-- [HAVING condition]
-- [ORDER BY column_name(s) [ASC | DESC]]
-- [LIMIT count]
-- [OFFSET count];

-- 理解sql语句的执行顺序
-- FROM
-- WHERE
-- group BY
-- HAVING
-- SELECT
-- order BY
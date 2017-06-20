-- or result is not null
SELECT c.country, COUNT(o.result)
FROM classes c
LEFT JOIN ships s ON c.class = s.class
LEFT JOIN outcomes o ON s.NAME = o.SHIP
WHERE result='sunk' OR result IS NOT NULL
GROUP BY c.country

-- Order by - Having
SELECT c.country, COUNT(o.result)
FROM classes c
INNER JOIN ships s ON c.class = s.class
INNER JOIN outcomes o ON s.NAME = o.SHIP
ORDER BY c.country
HAVING result = 'sunk'

-- вярно
SELECT c.country, COUNT(o.result)
FROM classes c
INNER JOIN ships s ON c.class = s.class
INNER JOIN outcomes o ON s.NAME = o.SHIP
WHERE result='sunk'
GROUP BY c.country

-- ще извади и тези с 0 потапяния
SELECT DISTINCT c.country, (SELECT COUNT(o.result)
	FROM classes c1 JOIN ships s on c1.CLASS = s.CLASS
	JOIN OUTCOMES o ON s.NAME = o.SHIP WHERE RESULT='sunk'
	AND c1.COUNTRY = c.country)
FROM classes c;
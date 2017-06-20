SELECT DISTINCT battle
FROM outcomes o1
WHERE
	(SELECT COUNT(DISTINCT country)
		FROM outcomes o , ships s, classes c
		WHERE o.SHIP = s.NAME AND c.CLASS = s.CLASS AND battle = o1.BATTLE)
	>
	(SELECT COUNT(DISTINCT country)
		FROM outcomes o , ships s, classes c
		WHERE o.SHIP = s.NAME AND c.CLASS = s.CLASS AND battle = 'North Cape')

-- Having без group by
SELECT DISTINCT battle
FROM outcomes, (SELECT COUNT(DISTINCT country) as NumCountries
				FROM outcomes o, ships s, classes c
				WHERE o.SHIP = s.NAME AND s.CLASS = c.CLASS
				AND battle = 'North Cape') as t
HAVING (SELECT COUNT(DISTINCT country)
		FROM outcomes o1, ships s, classes c
		WHERE o1.SHIP = s.NAME AND s.CLASS = c.CLASS AND battle = o1.BATTLE)
		>
		(SELECT NumCountries FROM t)

SELECT DISTINCT battle
FROM outcomes o, classes c, ships s
WHERE ship=name AND s.CLASS = c.CLASS
GROUP BY battle 
HAVING COUNT(DISTINCT country) > 
	(SELECT COUNT(country)
        FROM outcomes o, classes c, ships s
        WHERE ship=name AND s.CLASS = c.CLASS
        AND BATTLE = 'North Cape')

-- Не може да се сложи where под groupby - having
SELECT DISTINCT battle 
FROM outcomes o CROSS JOIN classes c
GROUP BY battle
HAVING COUNT(DISTINCT country) > (SELECT COUNT(DISTINCT country) FROM OUTCOMES o, CLASSES c)
WHERE battle = 'North Cape'
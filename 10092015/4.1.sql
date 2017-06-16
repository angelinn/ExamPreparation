-- Ще изведе само тези от MovieStar
SELECT MS.NAME, MS.ADDRESS
FROM MovieStar as MS
JOIN Studio S on MS.ADDRESS = S.ADDRESS
WHERE MS.ADDRESS LIKE '%Sofia%' AND gender = 'F'
ORDER BY MS.ADDRESS

-- Тази трябва да е вярна
SELECT * FROM (
	SELECT name, address
	FROM MOVIESTAR
	WHERE GENDER = 'F'
	UNION
	SELECT name, address
	FROM STUDIO
	) T
WHERE T.ADDRESS LIKE '%Sofia%'
ORDER BY T.ADDRESS

-- Първият ORDER BY не може да бъде там
SELECT name, address
FROM MOVIESTAR MS
WHERE GENDER = 'F' 
ORDER BY ADDRESS
UNION ALL
SELECT name, address
FROM Studio
WHERE address LIKE '%Sofia%'
ORDER BY address

-- При сечение ще се загубят еднакви записи, но пък и не иска да мине заявката
-- Incorrect syntax near 'Studio'
SELECT DISTINCT name, address
FROM MOVIESTAR INTERSECT STUDIO
WHERE address IS NOT NULL
AND GENDER LIKE 'F'
GROUP BY address
HAVING address LIKE '%Sofia%'

-- Full join + не се знае за чии променливи става въпрос
SELECT DISTINCT name, address
FROM MOVIESTAR
FULL JOIN Studio ON ADDRESS LIKE '%Sofia%'
WHERE GENDER LIKE 'F'
ORDER BY address
SELECT name, MOVIETITLE FROM moviestar
LEFT OUTER JOIN starsin ON name = starname
WHERE movieyear < 1970 OR movieyear > 1979 OR movieyear IS NULL

SELECT name, MIN(movieyear) - YEAR(birthdate) as debut_age FROM moviestar
INNER JOIN starsin ON name = starname
WHERE YEAR(birthdate) = 1955
GROUP BY name, birthdate

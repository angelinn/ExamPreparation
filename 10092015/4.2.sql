-- Няма смисъл от този 'предикат' в COUNT функцията - не минава заявката
SELECT name, address, AVG(length) as avgLength
FROM STUDIO
LEFT JOIN Movie ON name = STUDIONAME
GROUP BY STUDIONAME, ADDRESS
HAVING COUNT(inColor = 'y') <= 3


SELECT DISTINCT name, address, avgLength
FROM STUDIO, (SELECT studioName, AVG(length) as avgLength
			 FROM MOVIE
			 GROUP BY STUDIONAME) Averages
WHERE NAME = ANY (SELECT studioName 
				  FROM MOVIE
				  WHERE INCOLOR = 'n'
				  GROUP BY STUDIONAME
				  HAVING COUNT(title) <= 3)

SELECT Studio.NAME, STUDIO.ADDRESS, AVG(Movie.length) as avgLength
FROM MOVIE
RIGHT JOIN STUDIO ON STUDIONAME = NAME
GROUP BY NAME, ADDRESS
HAVING (SELECT COUNT(*) FROM MOVIE WHERE inColor = 'n') <= 3

SELECT name, address, AVG(length) as avgLength
FROM STUDIO
LEFT JOIN MOVIE on NAME = STUDIONAME
WHERE NAME NOT IN (SELECT STUDIONAME
				   FROM MOVIE
				   WHERE inColor = 'n'
				   GROUP BY STUDIONAME
				   HAVING COUNT(*) > 3)
GROUP BY NAME, ADDRESS
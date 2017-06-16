SELECT name FROM ships
WHERE launched IN (SELECT YEAR(date) FROM battles)
SELECT DISTINCT Maker FROM Product
INNER JOIN PC ON Product.Model = PC.Model
WHERE Maker IN (SELECT Maker FROM Product
                INNER JOIN Laptop on Product.Model = Laptop.Model
                )

SELECT Code, p.Model, Screen FROM Laptop
INNER JOIN Product p ON Laptop.Model = p.Model
WHERE (SELECT COUNT(*) FROM Printer
        INNER JOIN Product ON Printer.Model = Product.Model
        WHERE Product.Maker = p.Maker
        ) <= 2


CREATE TABLE Categories (id INTEGER PRIMARY KEY, type nvarchar(MAX))

CREATE TABLE Items (id INTEGER PRIMARY KEY, category_id INTEGER, manufacturer nvarchar(50),
					model nvarchar(20), client_name nvarchar(MAX),
					FOREIGN KEY(category_id) REFERENCES categories(id))

CREATE TABLE ItemDetails (item_id INTEGER PRIMARY KEY, year INTEGER CHECK (year > 1990),
							FOREIGN KEY(item_id) REFERENCES items(id))

CREATE TABLE Technicians (id INTEGER PRIMARY KEY, name nvarchar(100), egn nvarchar(10))
CREATE TABLE TechCategory (tech_id INTEGER, category_id INTEGER, PRIMARY KEY(tech_id, category_id),
							FOREIGN KEY(tech_id) REFERENCES technicians(id),
							FOREIGN KEY(category_id) REFERENCES categories(id))

CREATE TABLE Repair (item_id INTEGER, tech_id INTEGER, date DATE, price FLOAT,
						PRIMARY KEY(item_id, tech_id),
						FOREIGN KEY(item_id) REFERENCES items(id),
						FOREIGN KEY(tech_id) REFERENCES technicians(id))


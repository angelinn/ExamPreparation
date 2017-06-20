CREATE TABLE Agencies (id INTEGER PRIMARY KEY, name NVARCHAR(50), 
					website NVARCHAR(256) UNIQUE CHECK(website LIKE 'http://%' OR website LIKE 'https://%'))

CREATE TABLE Estates (id INTEGER PRIMARY KEY, description nvarchar(1000), city nvarchar(30),
						neighbourhood nvarchar(30), price FLOAT(2), area INTEGER, agency_id INTEGER,
						FOREIGN KEY(agency_id) REFERENCES agencies(id))
CREATE TABLE AdditionalInfos (estate_id INTEGER PRIMARY KEY, info nvarchar(50),
								FOREIGN KEY(estate_id) REFERENCES estates(id))

CREATE TABLE Apartments (estate_id INTEGER PRIMARY KEY, floor INTEGER, rooms INTEGER,
							FOREIGN KEY(estate_id) REFERENCES estates(id))
CREATE TABLE Parcels (estate_id INTEGER PRIMARY KEY, is_regulated BIT, 
						FOREIGN KEY(estate_id) REFERENCES estates(id))
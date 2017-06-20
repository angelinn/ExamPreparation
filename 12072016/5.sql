CREATE TABLE PlasticCards (id INTEGER PRIMARY KEY)
CREATE TABLE PlasticCardOwners (plastic_card_id INTEGER PRIMARY KEY, name NVARCHAR(100) NOT NULL,
								FOREIGN KEY (plastic_card_id) REFERENCES plasticcards(id))

CREATE TABLE Cards (id INTEGER PRIMARY KEY, price FLOAT(2) NOT NULL, plastic_card_id INTEGER,
					FOREIGN KEY(plastic_card_id) REFERENCES plasticcards(id))
CREATE TABLE TimedCards (card_id INTEGER PRIMARY KEY, begins DATE NOT NULL, expires DATE,
							FOREIGN KEY(card_id) REFERENCES cards(id))
CREATE TABLE TicketCards (card_id INTEGER PRIMARY KEY, tickets INTEGER NOT NULL,
							FOREIGN KEY(card_id) REFERENCES cards(id))

CREATE TABLE Lines (number INTEGER, type NVARCHAR(20) CHECK(type IN ('трамвай', 'метро', 'тролейбус')),
					card_id INTEGER, 
					PRIMARY KEY(number, type),
					FOREIGN KEY(card_id) REFERENCES timedcards(card_id))

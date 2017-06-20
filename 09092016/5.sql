CREATE TABLE Exams (id INTEGER PRIMARY KEY, title nvarchar(MAX))
CREATE TABLE Questions (id INTEGER PRIMARY KEY, points FLOAT(1) CHECK(points > 0))

CREATE TABLE Essays (question_id INTEGER PRIMARY KEY, FOREIGN KEY(question_id) REFERENCES questions(id))
CREATE TABLE Tests (question_id INTEGER PRIMARY KEY, correct_answer_id INTEGER, 
					FOREIGN KEY(question_id) REFERENCES questions(id))

CREATE TABLE Answers (id INTEGER PRIMARY KEY, test_id INTEGER, FOREIGN KEY (test_id) REFERENCES tests(question_id))
ALTER TABLE Tests ADD CONSTRAINT fk_answer_id FOREIGN KEY(correct_answer_id) REFERENCES answers(id)

CREATE TABLE Calculated (question_id INTEGER PRIMARY KEY, answer FLOAT,
							FOREIGN KEY(question_id) REFERENCES questions(id))

CREATE TABLE Requirements(exam_id INTEGER, required_id INTEGER, PRIMARY KEY(exam_id, required_id),
							FOREIGN KEY(exam_id) REFERENCES exams(id),
							FOREIGN KEY(required_id) REFERENCES exams(id))
							
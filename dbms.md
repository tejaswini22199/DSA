* Data base management system helps in collecting data and retrieving it efficiently.
* Advantages over normal file system are consistency, no redundancy, authorised access of data, concurrent access,backup.
## Normalisation



(End with semicolon in MYSQL)
* To create a table
CREATE TABLE Student(
    student_id INT,
    name VARCHAR(20),
    major VARCHAR(20),
    PRIMARY KEY(student_id)
);

CREATE TABLE Student(
    student_id INT PRIMARY KEY,
    name VARCHAR(20),
    major VARCHAR(20),
    
);

* To delete table
DROP TABLE Student;

* To view Table 
DESCRIBE Student;

* To add new columns or attributes

ALTER TABLE Student ADD GPA DECIMAL(3,2);

* To drop a column

ALTER TABLE Student DROP COLUMN GPA;

* To insert values

INSERT INTO Student VALUES(1,'JACK','Biology');

INSERT INTO Student(student_id,name) VALUES(1,'JACK');

UNIQUE  The column should have all values unique

NOT NULL CAn't be null


CREATE TABLE Student(
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20) DEFAULT 'UNDECIDED',
    major VARCHAR(20) UNIQUE,
    
);

UPDATE Student
SET major 'BIO'
where major='BIOLOGY';

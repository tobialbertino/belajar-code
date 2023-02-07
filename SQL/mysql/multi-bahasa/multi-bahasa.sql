CREATE DATABASE studi_kasus_multi_bahasa;

USE studi_kasus_multi_bahasa;

CREATE TABLE categories(
    id VARCHAR(100),
    position INT NOT NULL,

    PRIMARY KEY (id)
);

DESCRIBE categories;

INSERT INTO categories(id, position) VALUES ('FOOD', 1);
INSERT INTO categories(id, position) VALUES ('GADGET', 2);
INSERT INTO categories(id, position) VALUES ('FASHION', 3);

SELECT * FROM categories ORDER BY position;

CREATE TABLE categories_translation(
    category_id VARCHAR(100) NOT NULL,
    language VARCHAR(100) NOT NULL,
    name VARCHAR(100) NOT NULL,
    description TEXT,

    PRIMARY KEY (category_id, language)
);

DESCRIBE categories_translation;

ALTER TABLE categories_translation
ADD CONSTRAINT fk_categories_translation FOREIGN KEY (category_id)
REFERENCES categories(id);

INSERT INTO categories_translation(category_id, language, name, description)
VALUES ('FOOD', 'in_ID', 'Makanan', 'Deskripsi Makanan');
INSERT INTO categories_translation(category_id, language, name, description)
VALUES ('FOOD', 'en_US', 'Food', 'Food Description');
INSERT INTO categories_translation(category_id, language, name, description)
VALUES ('GADGET', 'in_ID', 'Gawai', 'Deskripsi Gawai');
INSERT INTO categories_translation(category_id, language, name, description)
VALUES ('GADGET', 'en_US', 'Gadget', 'Gadget Description');

SELECT * FROM categories
JOIN categories_translation ct ON categories.id = ct.category_id
WHERE ct.language = 'en_US' ORDER BY position;
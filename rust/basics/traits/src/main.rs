struct Film {
    title: String,
    director: String,
    studio: String,
}

struct Book {
    title: String,
    author: String,
    publisher: String,
}

trait Catalog {
    fn describe(&self) {
        println!("We need more information about this type of media")
    }
}

impl Catalog for Film {
    fn describe(&self) {
        println!(
            "{} was directed by {} through {} studios",
            self.title, self.director, self.studio
        )
    }
}

impl Catalog for Book {
    fn describe(&self) {
        println!(
            "{} was written by {} and published by {}",
            self.title, self.author, self.publisher
        )
    }
}

struct Album {
    title: String,
    artist: String,
    label: String
}

impl Catalog for Album {}

fn main() {
    let capt_marvel = Film {
        title: String::from("capt marvel"),
        director: String::from("capt marvel director"),
        studio: String::from("capt marvel studio"),
    };

    capt_marvel.describe();

    let elantris = Book{
        title: String::from("elantris"),
        author: String::from("elantris author"),
        publisher: String::from("elantris publisher"),
    };

    elantris.describe();

    let let_it_be = Album{
        title: String::from("example"),
        artist: String::from("example"),
        label: String::from("example"),
    };

    let_it_be.describe();
}

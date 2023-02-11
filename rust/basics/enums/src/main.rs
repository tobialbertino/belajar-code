enum WebEvent {
    PageLoad,
    PageUnload,
    KeyPress(char),
    Paste(String),
    Click { field1: i64, field2: i64 },
}

// has been publicly available
// enum Option<T> {
//     Some(T),
//     None
// }

fn main() {
    let _quit = WebEvent::KeyPress('q');
    let _page_load = WebEvent::PageLoad;
    let _page_unload = WebEvent::PageUnload;
    let _paste = WebEvent::Paste(String::from("Paste"));
    let click: WebEvent = WebEvent::Click { field1: 10, field2: 20 };
    if let WebEvent::Click { field1, field2 } = click {
        println!("x: {}, y: {}", field1, field2);
    }

    let _something = Some(1);
}

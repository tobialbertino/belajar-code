package data

class Note(title: String) {
    var title: String = title
        get() {
            println("Call getter func")
            return field
        }
        set(value) {
            println("Call Setter func")
            if (value.isNotBlank()) {
                field = value
            } else {
                println("Invalid title")
            }
        }
}

class BigNote(val title: String) {
    val bigTitle: String
    get() = title.uppercase()
}
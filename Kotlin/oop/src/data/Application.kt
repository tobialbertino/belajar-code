package data

class Application(val name: String) {

    companion object {
        fun toUpper(value: String): String {
            return value.uppercase()
        }
    }
}
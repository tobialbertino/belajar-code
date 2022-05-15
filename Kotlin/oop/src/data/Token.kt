package data

inline class Token(val value: String) {
    fun toUpper(): String {
        return this.value.uppercase()
    }
}
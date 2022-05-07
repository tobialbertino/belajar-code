fun main() {

    fun hello(name: String, transformer: (String) -> String): String {
        val nameTransform = transformer(name)
        return "Hello $nameTransform"
    }

    val lambdaUpper = { value: String -> value.uppercase() }
    println(hello("Eko", lambdaUpper))

    println(hello("Eko", { value: String -> value.lowercase() }))

    val result1 = hello("Eko", { value: String -> value.lowercase() })
    val result2 = hello("Eko") { value: String ->
        value.lowercase()
    }
}
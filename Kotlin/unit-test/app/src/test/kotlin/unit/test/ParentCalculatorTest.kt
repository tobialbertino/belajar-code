package unit.test

import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.extension.ExtendWith
import org.junit.jupiter.api.extension.Extensions
import unit.test.resolver.RandomParameterResolver

@Extensions(value = [
    ExtendWith(RandomParameterResolver::class)
])
abstract class ParentCalculatorTest {

    val calculator = Calculator()

    @BeforeEach
    fun beforeEach() {
        println("Before each")
    }

}
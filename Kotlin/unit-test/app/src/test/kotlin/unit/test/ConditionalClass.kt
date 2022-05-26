package unit.test

import jdk.jfr.Enabled
import org.junit.jupiter.api.*
import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.condition.*

class ConditionalClass {

    @Test
    @EnabledOnOs(value = [OS.WINDOWS, OS.LINUX])
    fun enableOnWindowsOrLinux() {
        // only windows or linux
    }

    @Test
    @DisabledOnOs(value = [OS.WINDOWS])
    fun disableOnWindows() {
        // disable windows
    }

    @Test
    @EnabledOnJre(value = [JRE.JAVA_13])
    fun onlyRunOnJava13() {}

    @Test
    @DisabledOnJre(value = [JRE.JAVA_13])
    fun disableRunOnJava13() {}

    @Test
    fun printSystemProperties() {
        System.getProperties().forEach { key, value ->
            println("$key => $value")
        }
    }

    @Test
    @EnabledIfSystemProperties(value = [
        EnabledIfSystemProperty(named ="java.vendor", matches = "oracle corporation")
    ])
    fun enableOnOravle() {

    }

    @Test
    @DisabledIfSystemProperties(value = [
        DisabledIfSystemProperty(named ="java.vendor", matches = "oracle corporation")
    ])
    fun disabledOnOravle() {

    }

    @Test
    @EnabledIfEnvironmentVariable(named = "PROFILE", matches = "DEV")
    fun enableOnDev() {}

    @Test
    @DisabledIfEnvironmentVariable(named = "PROFILE", matches = "DEV")
    fun disabledDev() {}
}
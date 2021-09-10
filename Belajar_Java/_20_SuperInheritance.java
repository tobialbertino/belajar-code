
class Hero{
    String name = "Class Hero";

    void display(){
        System.out.println("Ini adalah " + this.name);
    }
    void dummyMethod(){
        System.out.println("Method ini ada di SuperClass");
    }
}

class HeroStrength extends Hero{
    String name = "Class Strength";

    void display(){
        System.out.println("Ini adalah " + super.name); // Mengakses dari SuperClass, 
        // Super, Akan selalu mengakses SuperClass
        // this.dummyMethod();
        super.dummyMethod();
    }
    void dummyMethod(){
        System.out.println("Method ini ada di SubClass");
    }
}

public class _20_SuperInheritance{
    public static void main(String[] args) {
        Hero hero1 = new Hero();
        HeroStrength hero2 = new HeroStrength();

        hero1.display();
        hero2.display();
    }
}
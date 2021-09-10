
class Hero{
    String name;

    void display(){
        System.out.println("Hero Name : " + this.name);
    }
}

class HeroStrength extends Hero{
    double defensePower;
    // overriding method
    void display(){
        System.out.println("\nHero Strength");
        System.out.println("Hero Name : " + this.name);
        System.out.println("Defense   : " + this.defensePower);
    }
}

public class _19_Overriding{
    public static void main(String[] args) {
        Hero hero1 = new Hero();
        hero1.name = "Saitama";
        // hero1.defensePower = 100 // error
        hero1.display();

        HeroStrength hero2 = new HeroStrength();
        hero2.name = "Mountain Lady";
        hero2.defensePower = 100;
        hero2.display();
    }
}
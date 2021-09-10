
// inheritance adalah hubungan is-a
// super class
class Hero{
    String name;


    //method
    void diplay(){
        System.out.println("Name : " + this.name);
    }
}
// sub class, child class
class HeroStrength extends Hero{
// derived class
}
class HeroIntelligent extends Hero{
// derived class
}

public class _18_Inheritance{
    public static void main(String[] args) {
        Hero hero1 = new Hero();
        hero1.name = "Ucup";
        hero1.diplay();    
        
        HeroStrength hero2 = new HeroStrength();
        hero2.name = "Otong";
        hero2.diplay();    
        
        HeroIntelligent hero3 = new HeroIntelligent();
        hero3.name = "Michael";
        hero3.diplay();    
    }
}

class Player{
    private String name;
    private int baseHealth;
    private int baseAttack;
    private Armor armor;
    private Weapon weapon;
    private int level;
    private int incrementHealth;
    private int incrementAttack;

    public Player( String name ){
        this.name = name;
        this.baseHealth = 100;
        this.baseAttack = 100;
        this.level = 1;
        this.incrementHealth = 20;
        this.incrementAttack = 20;
    }
    public void display(){
        System.out.println("Player    : " + this.name);
        System.out.println("Level     : " + this.level);
        System.out.println("MaxHealth : " + this.maxHealth());
        System.out.println("Attack    : " + this.getAttack() + "\n");
    }
    public void levelUp(){
        this.level++;
    }
    public void setArmor(Armor armor){
        this.armor = armor;
    }
    public void setWeapon(Weapon weapon){
        this.weapon = weapon;
    }
    public int maxHealth(){
        return this.baseHealth + this.level*this.incrementHealth + this.armor.getAddHealth();
    }
    public int getAttack(){
        return this.baseAttack + this.level*this.incrementAttack + this.weapon.getAttack();
    }
}

class Weapon{
    private String name;
    private int attack;

    public Weapon(String name, int attack){
        this.name = name;
        this.attack = attack;
    }
    public int getAttack(){
        return this.attack;
    }
}

class Armor{
    private String name;
    private int strenght;
    private int health;

    public Armor(String name, int strenght, int health){
        this.name = name;
        this.strenght = strenght;
        this.health = health;
    }
    public int getAddHealth(){
        return this.strenght*10 + this.health;
    }
}

public class _11_latEncapsulasi{
    public static void main(String[] args) {

        Player player1 = new Player("Marni");
        Armor armor1 = new Armor("Baju Besi", 5, 100);
        Weapon weapon1 = new Weapon("Pedang", 10);
        player1.setArmor(armor1);
        player1.setWeapon(weapon1);
        
        Player player2 = new Player("Isabella");
        Armor armor2 = new Armor("Gaun Pesta", 1, 40);
        Weapon weapon2= new Weapon("Pecut", 40);
        player2.setArmor(armor2);
        player2.setWeapon(weapon2);
        
        player1.display();
        player2.display();
    }
}
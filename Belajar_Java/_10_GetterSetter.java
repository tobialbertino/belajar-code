
class Data{
    public int intPublic;
    private int  intPrivate;
    private double doublePrivate;

    public Data(){
        this.intPublic = 0;
        this.intPrivate = 10;
    }

    // GETTER
    public int getIntPrivate(){
        return this.intPrivate;
    }

    // SETTER
    public void setDoublePrivate(double value){
        this.doublePrivate = value;
    }
}

class Lingkaran{
    private double diameter;

    Lingkaran(double diameter){
        this.diameter = diameter;
    }
    // setter
    public void setJari2(double jari2){
        this.diameter = jari2*2;
    }
    // getter
    public double getJari2(){
        return this.diameter/2;
    }
    // getter
    public double getLuas(){
        return 3.14*this.diameter*this.diameter/4;
    }
}

public class _10_GetterSetter{
    public static void main(String[] args) {
        Data object = new Data();

        //public write & write
        object.intPublic = 5; // write
        System.out.println("Public : " + object.intPublic); // read

        // read only (dengan menggunakan GETTER)
        int angka = object.getIntPrivate();
        System.out.println("Getter : " + angka);

        //write only, hanya menulis (SETTER)
        object.setDoublePrivate(0.05);

        // gabungkan read dan write dengan setter dan getter
        Lingkaran object2 = new Lingkaran(5);
        System.out.println("jari-jari : " + object2.getJari2());
        object2.setJari2(14);
        System.out.println("jari-jari : " + object2.getJari2());
        System.out.println("luas : " + object2.getLuas());
    }
}
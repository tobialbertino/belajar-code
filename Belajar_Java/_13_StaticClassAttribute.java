
class Display{
    public static String type = "Display";
    private String name;
    
    Display (String name){
        this.name = name;
    }
    void setType(String type){
        Display.type = type; // recomend
        // this.type = type // alternatif
    }
    void show(){
        System.out.println("Display name = " + this.name);
    }
}

public class _13_StaticClassAttribute{
    public static void main(String[] args) {
        
        Display display1 = new Display("Monitor");
        display1.show();

        Display display2 = new Display("Smartphone");
        display2.show();

        // tampilkan static variabel / class variabel

        // kita coba ganti variabel staticnya
        display1.setType("Monitor");

        System.out.println("\nMenampilkan static variabel / class variabel");
        System.out.println(display1.type);
        System.out.println(display2.type);
        System.out.println(Display.type);

    }
}

class car
{
    int engineno;
    String car_type;
    car(int cno,String type)
    {
        engineno = cno;
        car_type = type;
    }
}

class alto extends car
{
    String color;
    alto(int cno, String type,String col)
    {
        super(cno,type);
        color=col;
    }
    void display()
    {
        System.out.println("Name = Alto");
        System.out.println("Engine Number = "+super.engineno);
        System.out.println("Car Type = "+super.car_type);
        System.out.println("Color = "+color);
    }
    public static void main(String[] args)
    {
        alto obj=new alto(1653398,"hatchback","yellow");
        obj.display();
    }
}

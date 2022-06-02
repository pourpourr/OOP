package askisi3;


public class Askisi3 {
public static void main (String[] args) {
		
	String str="panos";
    SecurityEmployee sec=new SecurityEmployee(str);
    CleaningEmployee cle=new CleaningEmployee(str);
    MaintenanceEmployee mai=new MaintenanceEmployee(str);

    Airplane boing747=new Airplane();

    
    System.out.println("====ready check before process==="+boing747.ready_check()+"\n");

    boing747.process(sec);
    boing747.process(mai);
    boing747.process(cle);

    System.out.println("===ready check for real===="+boing747.ready_check()+"\n");

	}
}

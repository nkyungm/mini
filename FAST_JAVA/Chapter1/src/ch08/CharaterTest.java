package ch08;

public class CharaterTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char ch1='A';
		System.out.println(ch1);
		System.out.println((int)ch1);
		
		char ch2=66;
		System.out.println(ch2);
		System.out.println((char)ch2);
		
		int ch3=67;
		System.out.println(ch3);
		System.out.println((char)ch3);
		
		//char ch=-66; //음수 사용 불가능
		char han='한';
		char ch='\uD55C'; //유니코드'
		
		System.out.println(han);
		System.out.println(ch);
	}

}

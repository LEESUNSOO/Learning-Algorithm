//3 bg
/* ������ ��
 * substring�� endidx�� ���Ե��� �ʴ´�
 * for�� ���� ���������� string�� �˻��� �� �� ������ ����Ͽ� ���������� ���Ѵ�.
 * ���ڿ� �񱳴�!!!!!!!!!!!!!!!!! equals~
 */
package hw.bg;

import java.util.Scanner;

public class Main_J_2514_���ڿ�ã��_�̼��� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String koi = "KOI";
		int ko = 0;
		String ioi = "IOI";
		int io = 0;
		
		for(int i = 0 ; i < s.length()-2; i++)
		{
			if(s.charAt(i) == 'K')
			{
				if(s.substring(i,  i+3).equals(koi))
					ko++;
			}
			else if(s.charAt(i) == 'I')
			{
				if(s.substring(i,  i+3).equals(ioi))
					io++;
			}		
		}
		
		System.out.println(ko);
		System.out.println(io);
		
		
	}

}

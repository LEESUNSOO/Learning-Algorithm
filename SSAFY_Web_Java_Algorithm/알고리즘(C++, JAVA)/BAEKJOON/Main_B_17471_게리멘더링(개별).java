package hw.ad;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class �Ը������ {
	
	static int[] population = new int[11];
	static HashSet<Integer> adjoin = new HashSet<Integer>();
	static ArrayList<Integer>[] locals = new ArrayList[11];
	static int N;
	static int minVal = 9999999;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < N; i++)
		{
			population[i] = Integer.parseInt(st.nextToken());
		}
		
		int nums;
		for(int i = 0; i < N; i++)
		{
			st = new StringTokenizer(br.readLine());
			nums = Integer.parseInt(st.nextToken());
			locals[i] = new ArrayList<>();
			for(int n = 0; n < nums; n++)
			{
				locals[i].add(Integer.parseInt(st.nextToken())-1);
			}
		}
		
		combination();
		
		if(minVal == 9999999)
			System.out.println(-1);
		else
			System.out.println(minVal);
	}
	
	static void combination()
	{
		for(int i = 1; i+1 < (1<<N); i++ ) 	// ���ǽĿ� i+1�� �� ������ ���δ� 1�� ä������ ��츦 �����ϴ� ���̴�.
		{									// ���δ� 1�� �� ��쿡�� �ᱹ �ϳ��� ���� ����� �Ǳ⶧���� �����Ѵ�.
			calcu(i);
		}
	}
	
	static void calcu(int bitLine)
	{
		HashSet<Integer> local_1, local_2;
		local_1 = new HashSet<Integer>();
		local_2 = new HashSet<Integer>();
		int local_1_sum, local_2_sum;
		local_1_sum = local_2_sum = 0;
		
		int maskLine;
		for(int i = 0; i < N; i++)
		{
			maskLine = (1<<i); // ������ idx���� �������� 1�� �ű�� �ش� ������ ���� �ִ��� Ȯ��
			if((bitLine & maskLine) != 0)
			{
				local_1.add(i); // 1�� �ش� ���� �߰�
				local_1_sum += population[i];
			}
			else
			{
				local_2.add(i); // 0�� �ش� ���� �߰�
				local_2_sum += population[i];
			}
		}
		
		
		// 0 ���� ����Ȯ��
		adjoin.clear();
		Iterator<Integer> it = local_1.iterator();
		int start = it.next().intValue();
		adjoin.add(start);
		dfs(start, local_1);
		
		Iterator<Integer> it_local = local_1.iterator();
		Iterator<Integer> it_adjoin = adjoin.iterator();

		if(local_1.size() != adjoin.size()) return; // ���������� ������ �ٸ� ��� �ٷ� return;
		
		while(it_local.hasNext() && it_adjoin.hasNext()) // ���ٸ� hashSet�� ����(���ϰ��� �����ϰ� �������ִ�)�� Ȱ���� ���ϰ���
		{
			if(it_local.next() != it_adjoin.next()) return;
		}

		// 1 ���� ����Ȯ��
		adjoin.clear();
		it = local_2.iterator();
		start = it.next().intValue();
		adjoin.add(start);
		dfs(start, local_2);
		
		it_local = local_2.iterator();
		it_adjoin = adjoin.iterator();

		if(local_2.size() != adjoin.size()) return; // ���������� ������ �ٸ� ��� �ٷ� return;
		
		while(it_local.hasNext() && it_adjoin.hasNext()) // ���ٸ� hashSet�� ����(���ϰ��� �����ϰ� �������ִ�)�� Ȱ���� ���ϰ���
		{
			if(it_local.next() != it_adjoin.next()) return;
		}
		
		minVal = Math.min(minVal, Math.abs(local_1_sum-local_2_sum));
	}
	
	static void dfs(int startLocal, HashSet<Integer> local)
	{
		for (int i : locals[startLocal]) // ���� ��ڽ��ϵ�? 		// -> startLocal�� �����ϴ� ���� �� �Ʒ��� ���� ����(����)�� �����ϸ� �� ������ �������� �� Ž��
		{													// �� ã�����ϴ� ������, arrayList�� ���� ������ �������� Ȯ�ε� ���̹Ƿ�
			if(!adjoin.contains(i) && local.contains(i)) 	// ����Ȯ�������� '����' && �˻��Ϸ��� local1 or 2 ������ �ִٸ�,
			{
				adjoin.add(i);	
				dfs(i, local);
			}
		}
	}

}

















package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 2350~1220
// �����̵�, �����̵� ���� �־ �̵���Ű��
// visit�� 3���� �迭�� ���μ��η� �ް�

public class Solution_8382_������ȯ_�̼��� {
	
	static class pos{
		int y;
		int x;
		int vh; // 0�̸� ����, 1�̸� ����
		public pos(int y, int x, int vh) {
			super();
			this.y = y;
			this.x = x;
			this.vh = vh;
		}
		
	}
	
	static pos start;
	static pos end;
	static boolean[][][] visit = new boolean[202][202][2]; // 0�� �����̵� , 1�� �����̵�
	static int[][] dir = new int[][] {{0,1},{1,0},{0,-1},{-1,0}}; // i%2 ==0 �����̵� , 1�� �����̵�
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			
			start = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
			end = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
			
			System.out.println("#" + t + " " + bfs(start));
			
			for(int i = 0 ; i < 202; i++)
			{
				for(int j = 0 ; j < 202; j++)
				{
					visit[i][j][0] = false;
					visit[i][j][1] = false;
				}
			}
		}
		
	}
	
	
	
	static int bfs(pos start)
	{
		int move = 0;
		
		Queue<pos> que = new LinkedList<pos>();
		que.add(start);
		que.add(new pos(start.y, start.x, 1));
		visit[start.y + 100][start.x+ 100][0] = true;
		visit[start.y+ 100][start.x+ 100][1] = true; // ��ֹ��̳� �ٸ� ������ ������ ���ڸ��� ���ƿ��°� �ּҰŸ����� �ʿ������
		
		int curY, curX, curVH;
		int ny, nx;
		pos cur;
		
		while(!que.isEmpty())
		{
			int size = que.size();
			
			while(size-- >0)
			{
				cur = que.poll();
				curY = cur.y;
				curX = cur.x;
				curVH = cur.vh;
				
				if(curY == end.y && curX == end.x)
					return move;
				for(int i = 0 ; i < 4; i++)
				{
					if(i%2 == curVH)
						continue;
					ny = curY + dir[i][0];
					nx = curX + dir[i][1];
					
					if(ny < -100 || nx < -100 || ny > 100 || nx > 100 || visit[ny+100][nx+100][i%2])
						continue;
					visit[ny+100][nx+100][i%2] = true;
					que.add(new pos(ny, nx, i%2));
				}
				
				
			}
			move++;
		}
		
		return move;	
	}
}











직선기준 점의 좌우측판단하기

if (line1.getPointOrientation(g_ptTest) > 0) { //진행방향을 바라보고 오른쪽
	_pen.SetColor(Color(255, 255, 0));
}
else { //왼쪽
	_pen.SetColor(Color(0, 255, 255));
}


bool collision(int pos_x1, int width_x1, int pos_x2, int width_x2) {
	if (pos_x1 + width_x1 >= pos_x2 && pos_x1 <= pos_x2 + width_x2)
		return true;
	else return false;
}

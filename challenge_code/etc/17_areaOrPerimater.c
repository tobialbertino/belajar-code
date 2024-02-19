// https://www.codewars.com/kata/5ab6538b379d20ad880000ab/train/javascript

int area_or_perimeter(int l, int w)
{
    if (l == w)
    {
        return l * w;
    }

    return (2 * l) + (2 * w);
}
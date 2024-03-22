// https://www.codewars.com/kata/568d0dd208ee69389d000016/solutions/c

/* d - the days to rent */
unsigned rental_car_cost(unsigned d)
{
    unsigned disc = 0u;
    if (d >= 7u)
    {
        disc = 50u;
    }
    else if (d >= 3u)
    {
        disc = 20u;
    }

    return (d * 40u) - disc;
}
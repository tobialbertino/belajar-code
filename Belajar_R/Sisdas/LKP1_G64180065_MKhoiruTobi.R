# No 1 ______________________________
re2f = function(n){
    f = (n * 9/4) + 32
    return(f)
}

a = re2f(37)
a
# a = 115.25

# No 2 _______________________________
Country = c('USA', 'India', 'Brazil', 'Russian', 'UK', 'France')
Cases_Cumulative = c(27491574, 10950201, 9921981, 4125598, 4071189, 3453645)
Death_Cumulative = c(485379, 156014, 240940, 81926, 118933, 82692)

df = data.frame(Country, Cases_Cumulative, Death_Cumulative)
df
mean_cases_cumulative = mean(df$Cases_Cumulative)
mean_cases_cumulative
total_death_cumulative = sum(df$Death_Cumulative)
total_death_cumulative
sortData = df[order(df$Country),]
sortData

# No 3
library(Deriv)

f = function(x) {
    x^3 + sqrt(x^2 + (2*x))
}
df = Deriv(f)
df(1)

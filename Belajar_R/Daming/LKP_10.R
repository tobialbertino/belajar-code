library(arules)
library(arulesViz)
# baca data
data = read.csv("C:/Users/TOBI/Documents/Belajar_R/Daming/Dataset/nursery/nursery.csv")
head(data)

# Ubah data menjadi data.frame
df = as.data.frame(data)
# Lihat 6 baris pertama
head(df)
# Lihat info df
summary(df)
nrow(df)
#------------------------------------------------------------------
# Praproses data -> Tidak perlu
# Ubah data hasil tabulasi menjadi per penumpang
## Ambil kolom selain "Freq"
# cols <- colnames(df)
# nursery <- sapply(cols,
#                   function(col) {
#                     ## Replikasi masing-masing nilai sebanyak "Freq"
#                     rep(df[, col], )
#                   })
# # Ubah matrix data menjadi data.frame
# nursery <- as.data.frame(nursery)

# # Ringkasan statistik
# summary(nursery)
#--------------------------------------------------------------------------------
# penerapan algoritme apriori 
rules = apriori(df)
# Urutkan rules berdasarkan "confidence"
rules <- sort(rules, by="confidence")
# Lihat 10 rules terbaik yang terbentuk
inspect(rules[1:10])

# Parameter yang akan diterapkan
params = list(minlen = 2,
              support = 0.05,
              confidence = 0.8)
# Terapkan algoritme
rules <- apriori(df, 
                parameter = params,
                appearance = list(rhs = c('class=not_recom', 
                'class=very_recom', 
                'class=priority', 
                'class=spec_prior'),
                default = 'lhs')
)

# No 4 
# Membentuk matriks hubungan subset
subset_matrix <- is.subset(rules, rules)
subset_matrix[lower.tri(subset_matrix)] <- FALSE
# Menentukan rules yang redundan
redundant <- colSums(subset_matrix) > 1
redundant
# Untuk melihat rules yang redundan: > which(redundant)

# Ambil rules yang tidak redundan
rules_pruned <- rules[!redundant]
inspect(rules_pruned)

# NO 5
plot(rules_pruned)
plot(rules_pruned, method='grouped')
plot(rules_pruned, method='graph')
plot(rules_pruned, method='graph', control=list(type='items'))

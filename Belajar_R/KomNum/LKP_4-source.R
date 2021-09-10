# Metode Eliminasi Gauss

scale_row <- function(m, row, k){
  m[row, ] <- m[row, ]*k
  return(m)
}
replace_row <- function(m, row1, row2, k){
  m[row2, ] <- m[row2, ] + m[row1, ]*k
  return(m)
}
gauss_jordan <- function (a){
  m <- nrow (a)
  n <- ncol (a)
  piv <- 1
  
  # cek elemen diagonal utama apakah bernilai nol
  for(row_curr in 1:m){
    if(piv <= n){
      i <- row_curr
      while(a[i, piv] == 0 && i < m){
        i <- i + 1
        if(i > m){
          i <- row_curr
          piv <- piv + 1
          if(piv > n)
            return (a)
        }
      }
      
      # jika diagonal utama bernilai nol,lakukan row swapping
      if(i != row_curr)
        a <- swap_row(a, i, row_curr)
      
      # proses pembentukan matriks reduced row echelon form
      piv_val <- a[row_curr , piv]
      a <- scale_row(a, row_curr , 1 / piv_val)
      for(j in 1: m){
        if(j != row_curr){
          k <- a[j, piv]/a[row_curr, piv]
          a <- replace_row (a, row_curr, j, -k)
        }
      }
      piv <- piv + 1
    }
  }
  return (a)
}
am <- c(2,-1,3,-2,
        -1,-2,3,2,
        3,-1,1,-2,
        -1,-1,3,2,
        11,-4,-2,4)
m <- matrix(am, nrow=4)
m
gauss_jordan(m)


# Faktorisasi Segitiga


lu_solve <- function(a, b=NULL){
  m <- nrow(a)
  n <- ncol(a)
  piv <- 1
  
  # membentuk matriks identitas P dan L
  P <- L <- diag(n)
  
  # cek elemen diagonal utama apakah bernilai nol
  for(row_curr in 1:m){
    if(piv <= n){
      i <- row_curr
      while(a[i, piv] == 0 && i < m){
        i <- i + 1
        if(i > m){
          i <- row_curr
          piv <- piv + 1
          if(piv > n)
            return(list(P = P, L = L, U = a))
        }
      }
      
      # jika elemen diagonal utama bernilai nol,lakukan row swapping
      if(i != row_curr){
        a <- swap_row(a, i, row_curr)
        P <- swap_row(P, i, row_curr)
      }
      
      # pembentukan matriks L dan U
      for(j in row_curr:m)
        if(j != row_curr){
          k <- a[j, piv]/a[row_curr, piv]
          
          # matriks U
          a <- replace_row(a, row_curr, j, -k)
          
          # pengisian elemen matriks L
          L[j, piv] <- k
        }
      piv <- piv + 1
    }
  }
  
  # penyelesaian persamaan linier
  if(is.null(b)){
    return(list(P = P, L = L, U = a))
  }else{
    
    # forward substitution
    t <- forwardsolve(L, b)
    
    # backward substitution
    x <- backsolve(a, t)
    return(list(P = P, L = L, U = a, result=x))
  }
}
# membuat matriks a dan vektor b
a <- matrix(c(2,-1,3,-2,
              -1,-2,3,2,
              3,-1,1,-2,
              -1,-1,3,2), nrow=4)
a
b <- c(11,-4,-2,4)
b
# penyelesaian
decomp<-lu_solve(a,b)
decomp
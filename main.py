#Permasalahan Knapsack dengan Dynamic Programming
def knapsack(n, c, w, v):
    """
         keterangan: 
         n = banyak item
         c = kapasitas knapsack
         w = weight
         v = value/profit
    """
    # Dimasukkan nol untuk kondisi awal
    value = [[0 for j in range(c + 1)] for i in range(n + 1)] 
    #perulangan untuk array integer
    for i in range(1, n + 1):
        for j in range(1, c + 1):
            value[i][j] = value[i - 1][j]
            #Jika kapasitas knapsack cukup untuk menampung objek saat ini
            #maka akan melanjutkan keadaan sebelumnya untuk diganti, dimana nilai[j] dipakai untuk hasil yang optimal
            if j >= w[i - 1] and value[i][j] < value[i - 1][j - w[i - 1]] + v[i - 1]:
                value[i][j] = value[i - 1][j - w[i - 1]] + v[i - 1]
    for x in value:
        #untuk menampilkan matrix 
        print(x)
    return value

def show(n, c, w, value):
    print('Hasil maksimalnya adalah:', value[n][c])
    x = [False for i in range(n)]
    j = c
    for i in range(n, 0, -1):
        if value[i][j] > value[i - 1][j]:
            x[i - 1] = True
            j -= w[i - 1]
    print('Barang yang diambil yaitu:')
    for i in range(n):
        if x[i]:
            print('Barang ke-',i+1,".",end='')

def knapsack1(n, c, w, v):
    values = [0 for i in range(c+1)]
    for i in range(1, n + 1):
        for j in range(c, 0, -1):
            # mengecek apakah berat barang i saat ini kurang dari atau sama dengan kapasitas knapsack
            #lalu mengambil nilai maksimal dari item
            if j >= w[i-1]:
                values[j] = max(values[j-w[i-1]]+v[i-1], values[j])
                
    return values

#fungsi program utama
if __name__ == '__main__':
    n = 3
    c = 5
    w = [2, 3, 1]
    v = [65, 80, 30]
    value = knapsack(n, c, w, v)
    #menampilkan matrix yang optimum
    show(n, c, w, value)
    print('\nSolusi optimum tahap akhir:', knapsack1(n, c, w, v))


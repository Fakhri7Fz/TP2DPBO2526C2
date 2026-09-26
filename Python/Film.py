from KaryaSeni import KaryaSeni


class Film(KaryaSeni):
    # =========================
    # CONSTRUCTOR
    # =========================

    def __init__(
        self,
        id="",
        judul="",
        tahunRilis=0,
        pencipta="",
        genre="",
        durasi=0,
        harga=0
    ):
        super().__init__(
            id,
            judul,
            tahunRilis,
            pencipta
        )

        self._genre = genre
        self._durasi = durasi
        self._harga = harga

    # =========================
    # METHOD GETTER
    # =========================

    def getGenre(self):
        return self._genre

    def getDurasi(self):
        return self._durasi

    def getHarga(self):
        return self._harga

    # =========================
    # METHOD SETTER
    # =========================

    def setGenre(self, genre):
        self._genre = genre

    def setDurasi(self, durasi):
        self._durasi = durasi

    def setHarga(self, harga):
        self._harga = harga

    # =========================
    # METHOD LAIN
    # =========================

    # Method untuk menampilkan informasi film
    def tampilkan_info(self):
        print(f"ID              : {self._id}")
        print(f"Judul           : {self._judul}")
        print(f"Tahun Rilis     : {self._tahunRilis}")
        print(f"Pencipta        : {self._pencipta}")
        print(f"Genre           : {self._genre}")
        print(f"Durasi          : {self._durasi} menit")
        print(f"Harga           : Rp{self._harga}")
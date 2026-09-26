from Film import Film


class FilmAnimasi(Film):
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
        harga=0,
        studioAnimasi="",
        teknikAnimasi="",
        pengisiSuara=None
    ):
        super().__init__(
            id,
            judul,
            tahunRilis,
            pencipta,
            genre,
            durasi,
            harga
        )

        if pengisiSuara is None:
            pengisiSuara = []

        self.__studioAnimasi = studioAnimasi
        self.__teknikAnimasi = teknikAnimasi
        self.__pengisiSuara = pengisiSuara

    # =========================
    # METHOD GETTER
    # =========================

    def getStudioAnimasi(self):
        return self.__studioAnimasi

    def getTeknikAnimasi(self):
        return self.__teknikAnimasi

    def getPengisiSuara(self):
        return self.__pengisiSuara

    # =========================
    # METHOD SETTER
    # =========================

    def setStudioAnimasi(self, studioAnimasi):
        self.__studioAnimasi = studioAnimasi

    def setTeknikAnimasi(self, teknikAnimasi):
        self.__teknikAnimasi = teknikAnimasi

    def setPengisiSuara(self, pengisiSuara):
        self.__pengisiSuara = pengisiSuara

    # =========================
    # METHOD LAIN
    # =========================

    # Method untuk menampilkan informasi film animasi
    def tampilkan_info(self):
        print(f"ID              : {self._id}")
        print(f"Judul           : {self._judul}")
        print(f"Tahun Rilis     : {self._tahunRilis}")
        print(f"Pencipta        : {self._pencipta}")
        print(f"Genre           : {self._genre}")
        print(f"Durasi          : {self._durasi} menit")
        print(f"Harga           : Rp{self._harga}")
        print(f"Studio Animasi  : {self.__studioAnimasi}")
        print(f"Teknik Animasi  : {self.__teknikAnimasi}")

        print("Pengisi Suara   :")

        for voice_actor in self.__pengisiSuara:
            print(f"- {voice_actor}")
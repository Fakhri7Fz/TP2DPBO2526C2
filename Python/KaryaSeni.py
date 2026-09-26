class KaryaSeni:
    # =========================
    # CONSTRUCTOR
    # =========================

    def __init__(self, id="", judul="", tahunRilis=0, pencipta=""):
        self._id = id
        self._judul = judul
        self._tahunRilis = tahunRilis
        self._pencipta = pencipta

    # =========================
    # METHOD GETTER
    # =========================

    def getId(self):
        return self._id

    def getJudul(self):
        return self._judul

    def getTahunRilis(self):
        return self._tahunRilis

    def getPencipta(self):
        return self._pencipta

    # =========================
    # METHOD SETTER
    # =========================

    def setId(self, id):
        self._id = id

    def setJudul(self, judul):
        self._judul = judul

    def setTahunRilis(self, tahunRilis):
        self._tahunRilis = tahunRilis

    def setPencipta(self, pencipta):
        self._pencipta = pencipta

    # =========================
    # METHOD LAIN
    # =========================

    # Method untuk menampilkan informasi karya seni
    def tampilkan_info(self):
        print(f"ID              : {self._id}")
        print(f"Judul           : {self._judul}")
        print(f"Tahun Rilis     : {self._tahunRilis}")
        print(f"Pencipta        : {self._pencipta}")
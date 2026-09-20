# implement assets loading

- STATUS: OPEN
- PRIORITY: 100
- TAGS: assets

Assets loading based on .zip file, to avoid shipping whole ars
folder of resource, or maybe use windows resource file or maybe use
my own custom file format.

---

Proposed API:

```c
void  asset_load_zip(const char* path);
void* asset_get(const char* path);

void asset_unload(void*);

```



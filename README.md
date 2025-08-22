# Guide const C++

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

> Guide rapide et essentiel pour maîtriser `const` en C++

## 🔧 Variables const

```cpp
// ✅ Pour les valeurs qui ne changent jamais
const int MAX_SIZE = 100;
const std::string MSG = "Hello";

// ❌ Si la variable doit changer
// const int counter = 0;
// counter++; // ERREUR !
```

## 👉 Pointeurs et const

```cpp
// 1️⃣ Pointeur vers const (données protégées)
const int* ptr;        // Ne peut pas modifier *ptr
ptr = &other;          // ✅ OK - peut changer de cible

// 2️⃣ Pointeur const (pointeur protégé)  
int* const ptr = &var; // Ne peut pas changer de cible
*ptr = 42;             // ✅ OK - peut modifier la valeur

// 3️⃣ Les deux (protection maximale)
const int* const ptr = &var;  // Rien ne peut changer
```

## 🔗 Références const

```cpp
// ✅ Pour gros objets (évite copie)
void process(const std::vector<int>& vec) { /* lecture seule */ }

// ❌ Inutile pour types primitifs
void calc(int a, int b) { /* plus simple */ }

// ❌ Si on doit modifier
void increment(int& value) { value++; }
```

## ⚙️ Méthodes const

```cpp
class Student {
    std::string name;
    int age;
    
public:
    // ✅ Getters/lecture - TOUJOURS const
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    bool isAdult() const { return age >= 18; }
    
    // ❌ Setters/modification - JAMAIS const
    void setName(const std::string& n) { name = n; }
    void celebrate() { age++; }
};
```

## 📥 Paramètres const

```cpp
// ✅ Gros objets en lecture
void display(const Book& book);

// ✅ Protection des données
void print(const char* text);

// ❌ Types primitifs (inutile)
void add(int a, int b);  // Plus simple que const int&

// ❌ Si modification nécessaire
void sort(std::vector<int>& data);
```

## 🏗️ Membres const

```cpp
class Circle {
    const double radius;    // ✅ Fixe après construction
    const int id;          // ✅ Identifiant unique
    int area;              // ❌ Pas const - calculé/modifiable
    
public:
    Circle(double r, int i) : radius(r), id(i) {}
};
```

## 🎯 Objets const

```cpp
const Config config("localhost", 8080);  // ✅ Configuration immuable

// Limitations :
config.getHost();     // ✅ OK - méthodes const seulement
// config.setPort(80); // ❌ ERREUR - méthode non-const
```

## ❌ Quand NE PAS utiliser const

```cpp
// Variables qui doivent changer
int userInput = getUserInput();  // Pas const !

// Paramètres à modifier
void swap(int& a, int& b);       // Pas const& !

// Méthodes qui modifient
Counter& operator++() { count++; return *this; }  // Pas const !
```

## ✨ Règles d'or

| **Contexte** | **const si** | **Pas const si** |
|--------------|--------------|-------------------|
| **Variable** | Ne change jamais | Doit être modifiée |
| **Paramètre** | Gros objet lecture | Modification nécessaire |
| **Méthode** | Ne modifie rien | Modifie des membres |
| **Membre** | Fixe après construction | Change pendant la vie |

## 🎯 Bonnes pratiques

```cpp
// ✅ Commencer par const, enlever si nécessaire
const auto value = getValue();
const auto& ref = getLargeObject();

// ✅ Dans les boucles
for (const auto& item : container) { /* ... */ }

// ✅ Interface cohérente
class TextProcessor {
public:
    std::string process(const std::string& input) const;  // Lecture
    void addFilter(const Filter& filter);                 // Modification
};
```

## 🏆 En résumé

> **const = "Je promets de ne pas modifier"**

- ✅ **Variables** : valeurs constantes
- ✅ **Méthodes** : getters et fonctions lecture
- ✅ **Paramètres** : gros objets en lecture (`const&`)
- ✅ **Membres** : valeurs fixes après construction

**Règle ultime** : Utilise `const` partout où c'est logique, enlève seulement si tu dois modifier !

---

## 🔗 Ressources utiles

- [CPP Reference - const](https://en.cppreference.com/w/cpp/language/const)
- [Core Guidelines - const correctness](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con-constants-and-immutability)
- [Effective C++ par Scott Meyers](https://www.aristeia.com/books.html)

---

**Fait avec ❤️ pour la communauté 42**

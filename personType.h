/*
    Programmer: Ryan Posey
    Assignment: L12D
    Purpose: Practice dynamic memory allocation
    Due date: 11/16/2025
*/
#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

#include <cstdint>
#include <string>
#include <vector>

/**
 * \class personType
 * \brief Abstract base class for people (identity + demographics).
 * \details Provides common data members (name, address, DOB, gender,
 * height, age) and optional parent pointers (mother/father). It cannot
 * be instantiated directly because it declares pure virtual functions
 * `print()` and `equals()`. Derived concrete classes (e.g. studentType,
 * professorType) must implement role-specific output and equality.
 * Parent pointers are non-owning raw pointers that may be nullptr.
 */
class personType { 
    /** \brief First name (may be sentinel like "Not Set"). */
    std::string firstName_;

    /** \brief Last name (may be empty). */
    std::string lastName_;

    /** \brief Postal address or sentinel string. */
    std::string address_;

    /** \brief Height in inches (clamped to [0.0, 120.0]). */
    double height_inches_{};

    /** \brief Date of birth string (format application-defined). */
    std::string date_of_birth_;

    /** \brief Gender character (application-defined semantics). */
    char gender_{};

    /** \brief Age in years (clamped to [0,999]). */
    uint16_t age_{};

    personType* mother {nullptr};
    personType* father {nullptr};

public:
    /**
     * @brief Full constructor.
     *
     * @param firstName First name string.
     * @param lastName Last name string.
     * @param address Address string.
     * @param height Height in inches (will be clamped to [0,120]).
     * @param DOB Date of birth string.
     * @param gender Gender character.
     * @param age Age (uint16_t, will be clamped to [0,999]).
     * @pre  Strings are valid; height and age are finite numeric values.
     * @post Constructs a personType with the provided values (clamped where applicable).
     * @details
     * Use this constructor when you have all personal fields available at the
     * time of construction.
     *
     * @example
     * @code{.cpp}
     * personType p("Jane","Doe","1 Main St",65.0,"1990-01-01",'F',30);
     * @endcode
     */
    personType(
        const std::string& firstName, const std::string& lastName, const std::string& address, 
        double height, const std::string& DOB, char gender, uint16_t age
    ); // Full constructor

    /**
     * @brief Constructor taking first and last name only.
     *
     * @param firstName First name string.
     * @param lastName Last name string.
     * @pre  Strings are valid.
     * @post Constructs a personType with name and default sentinel values for other fields.
     * @example
     * @code{.cpp}
     * personType p("John","Smith");
     * @endcode
     */
    personType(const std::string& firstName, const std::string& lastName); // First+Last constructor

    /**
     * @brief Default constructor.
     *
     * @pre  None.
     * @post Constructs a personType with sentinel/default values.
     * @example
     * @code{.cpp}
     * personType p;
     * @endcode
     */
    personType(); // Default constructor

    /**
     * @brief Shallow copy constructor.
     *
     * Constructs a new personType by copying the scalar and std::string
     * members from @p other. Parent pointers (`mother` and `father`) are
     * copied as-is (shallow copy) — no new person objects are created and
     * ownership is not transferred. This preserves the non-owning pointer
     * semantics used throughout the codebase.
     *
     * @param other The personType to copy from.
     * @pre  @p other is a valid, constructed personType.
     * @post The new object has the same field values as @p other. Both
     *       objects may point to the same mother/father objects (if set).
     */
    personType(const personType& other);

    /**
     * @brief Virtual destructor.
     *
     * Declared virtual to allow safe polymorphic deletion if this class
     * is used as a base for derived types.
     *
     * @pre  Object is valid.
     * @post Performs cleanup (none required for this type).
     */
    virtual ~personType();

    /**
     * @brief Pure virtual: print a formatted, role-specific representation.
     * @pre std::cout is available.
     * @post Streams a human-readable representation to stdout.
     */
    virtual void print() const = 0;

    /**
     * @brief Pure virtual: polymorphic equality comparison.
     * @param other Reference to another personType.
     * @return true if both base fields and role-specific fields match.
     * @details Derived implementations should use baseEquals(other) then
     * compare their own additional members.
     */
    virtual bool equals(const personType& other) const = 0;

protected:
    /**
     * @brief Compare only base-class fields (case-insensitive where appropriate).
     * @param other Another personType.
     * @return true if all base members match.
     */
    bool baseEquals(const personType& other) const;

public: // Expose setters/getters publicly for driver usage
    // Setters
    /**
     * @brief Set the full name from a single "First Last" string (splits on whitespace).
     *
     * @param name Full name string.
     * @pre  name is a valid std::string.
     * @post firstName_ and lastName_ are updated accordingly.
     */
    void setName(const std::string& name);               // accepts "First Last" (splits)
    /** \brief Set first name. */
    void setFirstName(const std::string& firstName);
    /**
     * @brief Set the last name.
     */
    void setLastName(const std::string& lastName);
    /**
     * @brief Set the address.
     */
    void setAddress(const std::string& address);
    /**
     * @brief Set the height in inches (clamped to [0,120]).
     */
    void setHeight(double height);
    /**
     * @brief Set the date of birth string.
     */
    void setDOB(const std::string& DOB);
    /**
     * @brief Set the gender character.
     */
    void setGender(char gender);
    /**
     * @brief Set the age (clamped to [0,999]).
     */
    void setAge(uint16_t age);

    /** \brief Set this person's mother pointer (may be nullptr). */
    void setMother(personType* mother);

    /** \brief Set this person's father pointer (may be nullptr). */
    void setFather(personType* father);

    // Getters
    /**
     * @brief Return the full name as "First Last" (omits last if empty).
     */
    std::string getName() const;         // returns "First Last"
    /** \brief Get first name. \return First name string. */
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getAddress() const;
    double getHeight() const;
    std::string getDOB() const;
    char getGender() const;
    uint16_t getAge() const;

    static int getTallest(const std::vector<personType>& people);
    static int getOldest(const std::vector<personType>& people);
    static int getYoungest(const std::vector<personType>& people);
    /** \brief Get pointer to this person's mother (may be nullptr). */
    personType* getMother() const;

    /** \brief Get pointer to this person's father (may be nullptr). */
    personType* getFather() const;


    // Operator overloading
    
    bool operator<(const personType& rhs);

    friend std::ostream& operator<<(std::ostream& os, const personType& p);
};

#endif // PERSON_TYPE_H
#pragma once

#include "cell.h"
#include "common.h"

#include <functional>
#include <unordered_map>

class CompForCell {
public:
    bool operator()(const Position& lhs, const Position& rhs) const {
        return lhs == rhs;
    }
};

class HasherForCell {
public:
    size_t operator()(const Position p) const {
        return std::hash<std::string>()(p.ToString());
    }
};


class Sheet : public SheetInterface {
public:
    using Table = std::unordered_map<Position, std::unique_ptr<Cell>, HasherForCell, CompForCell>;

    ~Sheet();

    void SetCell(Position pos, std::string text) override;

    const CellInterface* GetCell(Position pos) const override;
    CellInterface* GetCell(Position pos) override;

    void ClearCell(Position pos) override;

    Size GetPrintableSize() const override;

    void PrintValues(std::ostream& output) const override;
    void PrintTexts(std::ostream& output) const override;

    const Cell* GetConcreteCell(Position pos) const;
    Cell* GetConcreteCell(Position pos);

private:
	Table cells_;
};
